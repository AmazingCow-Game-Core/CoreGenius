//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.cpp                              //
//            █ █        █ █        CoreGenius                                //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
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
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "../include/GameCore.h"

//Usings
USING_NS_COREGENIUS;

// CTOR/DTOR //
GameCore::GameCore(int sidesCount, int seed /* kRandomSeed */) :
    //m_sequence - Set in generateNextSide
    m_status       (Status::None),
    m_currentIndex (0),
    m_sidesCount   (sidesCount),
    m_random       (seed)
{
    //Empty...
}

// Public Methods //
int GameCore::generateNextSide()
{
    //Generate a random side in range (0, m_sidesCount).
    int side = m_random.next(0, m_sidesCount);
    m_sequence.push_back(side);

    return side;
}

GameCore::Status GameCore::checkSideGuess(int guessSide)
{
    //Check if player hit or miss the current side.
    //If player hit, check if is sequence is over and
    //then generate a new side.
    auto currentSide = m_sequence[m_currentIndex];

    //Player miss the side.
    if(currentSide != guessSide)
    {
        m_status = Status::Wrong;
        m_currentIndex = 0;
    }

    //Player hit and the guess is the last of current sequence.
    else if(m_currentIndex == getSequenceSize() - 1)
    {
        m_status = Status::CorrectAndFinish;
        m_currentIndex = 0;
    }

    //Player hit but the sequence is not over yet.
    else
    {
        m_status = Status::CorrectAndContinue;
        ++m_currentIndex;
    }

    return m_status;
}
int GameCore::getCurrentSideGuessIndex() const
{
    return m_currentIndex;
}

const GameCore::Sequence& GameCore::getSequence() const
{
    return m_sequence;
}
int GameCore::getSequenceSize() const
{
    return static_cast<int>(m_sequence.size());
}

GameCore::Status GameCore::getStatus() const
{
    return m_status;
}

int GameCore::getSeed() const
{
    return m_random.getSeed();
}
