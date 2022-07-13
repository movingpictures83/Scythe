#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ScythePlugin.h"

void ScythePlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void ScythePlugin::run() {
   
}

void ScythePlugin::output(std::string file) {
	//cutadapt S12_R1.fastq -a CNCCACTCT -o S12_R1.trimmed.fastq
	// ./scythe -a illumina_adapters.fa /biorg/data/RNA/UMiami/Illumina/S12_R1.illumina.fastq -o output.fastq
	
	std::string command = "scythe -a "+std::string(PluginManager::prefix())+"/"+parameters["adapters"];
 command += " "+std::string(PluginManager::prefix())+"/"+parameters["fastqfile"];
 command += " -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<ScythePlugin> ScythePluginProxy = PluginProxy<ScythePlugin>("Scythe", PluginManager::getInstance());
