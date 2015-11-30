//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        main.cpp                                  //
//             ████████████         CoreGenius                                //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//


//This guard is to ease the usage of the CoreGenius,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_COREGENIUS_TEST_ENABLED__

#include <iostream>
#include <cstdlib>
#include "../include/CoreGenius.h"

USING_NS_COREGENIUS;
using namespace std;

void usage()
{
    cout << "Amazing Cow - CoreGenius Test Game" << endl;
    cout << "Usage:" << endl;
    cout << "  <binary-name> [seed]" << endl;
    cout << "Ex: ./testgame 2 //Init with seed 2" << endl;

    exit(1);
}

int main(int argc, const char *argv[])
{
    if(argc != 2)
        usage();

    auto seed = atoi(argv[1]);

    GameCore core(4, seed);
    core.generateNextSide();

    while(core.getStatus() != GameCore::Status::Wrong)
    {
        //Print the sequence.
        cout << "Sequence is:" << endl;
        for(auto side : core.getSequence())
            cout << side << " ";
        cout << endl;

        do {
            //Display the prompt.
            cout << "Guess ("
                 << core.getCurrentSideGuessIndex()
                 << ") of ( "
                 << core.getSequenceSize()
                 << "):" << endl;
            cout << "Guess: ";

            int guess;
            cin >> guess;

            core.checkSideGuess(guess);
        } while(core.getStatus() == GameCore::Status::CorrectAndContinue);

        if(core.getStatus() == GameCore::Status::CorrectAndFinish)
        {
            cout << "Congrats - Lets continue" << endl;
            core.generateNextSide();
        }
        else
        {
            cout << "OHHHH no..." << endl;
        }
    }
}

#endif // __AMAZINGCORE_CoreGenius_TEST_ENABLED__ //
