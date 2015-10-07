//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                // 
//             ████████████         Genius Core                               //
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

#ifndef __GeniusCore_include_GameCore_h__
#define __GeniusCore_include_GameCore_h__

//std
#include <vector>
#include <random>
//GeniusCore.
#include "GeniusCore_Utils.h"

NS_GENIUSCORE_BEGIN

class GameCore
{
    // Enums/Constants/Typedefs //
public:
    ///@brief 
    ///@param
    ///@returns
    ///@see
    static const int kRandomSeed;
    
    ///@brief 
    ///@param
    ///@returns
    ///@see
    enum class Status 
    {
        CorrectAndContinue,
        CorrectAndFinish,
        Wrong,
        None
    };
    
    ///@brief 
    ///@param
    ///@returns
    ///@see
    typedef std::vector<int> Sequence;
    

    // CTOR/DTOR //
public:
    ///@brief 
    ///@param
    ///@returns
    ///@see
    GameCore(int sidesCount, int seed = kRandomSeed);
    

    // Public Methods //
public:
    ///@brief 
    ///@param
    ///@returns
    ///@see
    int generateNextSide();
    
    
    ///@brief 
    ///@param
    ///@returns
    ///@see
    Status checkSideGuess(int guessSide);

    ///@brief 
    ///@param
    ///@returns
    ///@see
    int getCurrentSideGuessIndex() const;
    

    ///@brief 
    ///@param
    ///@returns
    ///@see
    const Sequence& getSequence() const;

    ///@brief 
    ///@param
    ///@returns
    ///@see
    int getSequenceSize() const;
    
    
    ///@brief 
    ///@param
    ///@returns
    ///@see
    Status getStatus() const;
    
    ///@brief 
    ///@param
    ///@returns
    ///@see
    int getSeed() const;
    

    // Private Methods //
private:
    void initRandomGenerator();
    

    // iVars //
private:
    Sequence m_sequence;
    Status   m_status;
    
    int m_currentIndex;
    
    int m_sidesCount;
    int m_seed;
};

NS_GENIUSCORE_END
#endif // defined(__GeniusCore_include_GameCore_h__) //
