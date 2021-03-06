//
// Created by simone on 02/09/18.
//

#include "ProgramArguments.h"
#include <getopt.h> // For options check

void ProgramArguments::printProgramUsage(){
    cout << endl << "Usage: FeatureExtractor [<-s>] [<-i>] [<-d distance>] [<-w windowSize>] [<-n directionType>] "
                    "imagePath" << endl;
    exit(2);
}

ProgramArguments ProgramArguments::checkOptions(int argc, char* argv[]){
    ProgramArguments progArg;
    int opt;
    while((opt = getopt(argc, argv, "sw:d:in:hct:")) != -1){
        switch (opt){
            case 'c':{
                // Crop original dynamic resolution
                progArg.crop = true;
                break;
            }
            case 's':{
                // Make the glcm pairs symmetric
                progArg.symmetric = true;
                break;
            }
            case 'i':{
                // Create images associated to features
                progArg.createImages = true;
                break;
            }
            case 'd': {
                int distance = atoi(optarg);
                if (distance < 1) {
                    cout << "ERROR ! The distance between every pixel pair must be >= 1 ";
                    printProgramUsage();
                }
                progArg.distance = distance;
                break;
            }
            case 'w': {
                // Decide what the size of each sub-window of the image will be
                short int windowSize = atoi(optarg);
                if ((windowSize < 2) || (windowSize > 10000)) {
                    cout << "ERROR ! The size of the sub-windows to be extracted option (-w) "
                            "must have a value between 2 and 10000";
                    printProgramUsage();
                }
                progArg.windowSize = windowSize;
                break;
            }
            case 't':{
                // Decide how many of the 4 directions will be copmuted
                short int dirType = atoi(optarg);
                if(dirType > 4 || dirType <1){
                    cout << "ERROR ! The type of directions to be computed "
                            "option (-t) must be a value between 1 and 4" << endl;
                    printProgramUsage();
                }
                progArg.directionType = dirType;

                break;
            }
            case 'n':{
                short int dirNumber = atoi(optarg);
                if(dirNumber != 1){
                    cout << "Warning! At this moment just 1 direction "
                            "can be be computed at each time" << endl;
                    printProgramUsage();
                }
                progArg.directionType = dirNumber;
                break;
            }
            case '?':
                // Unrecognized options
                printProgramUsage();
            case 'h':
                // Help
                printProgramUsage();
                break;
            default:
                printProgramUsage();
        }


    }
    if(progArg.distance > progArg.windowSize){
        cout << "WARNING: distance can't be > of each window size; distance value corrected to 1" << endl;
        progArg.distance = 1;
    }
    // The last parameter must be the image path
    if(optind +1 == argc){
        cout << "imagepath: " << argv[optind];
        progArg.imagePath = argv[optind];
    } else{
        progArg.imagePath= "../../../SampleImages/brainAltered.tiff";
        /*
        cout << "Missing image path!" << endl;
        printProgramUsage();
        */
    }
    return progArg;
}