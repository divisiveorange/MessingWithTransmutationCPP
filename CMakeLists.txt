cmake_minimum_required(VERSION 4.0)
project(TransmutationFun)

set(CMAKE_CXX_STANDARD 23)

add_executable(TransmutationFun src/main.cpp
        src/ArenaStack/ArenaStack.h
        src/ArenaStack/Arena.h
        src/ArenaStack/ArenaAlone.h
        src/ArenaStack/ArenaWithNext.h
        src/ArenaStack/FullArena.h
        src/ArenaStack/IncreasableArena.h
        src/ArenaStack/FullAlone.h
        src/ArenaStack/FullWithNext.h
        src/ArenaStack/IncreasableAlone.h
        src/ArenaStack/IncreasableWithNext.h
        src/ArenaStack/TransFullAlone.h
        src/ArenaStack/TransFullWithNext.h
        src/ArenaStack/TransIncreasableAlone.h
        src/ArenaStack/TransIncreasableWithNext.h
        src/GeneralLib/PaddingForTrans.h
        src/ArenaStack/ArenaMultiType.h
        src/Forest/Node.h
        src/Forest/Top.h
        src/Forest/NonTop.h
        src/Forest/Bottom.h
        src/Forest/NonBottom.h
        src/Forest/Lonely.h
        src/Forest/Middle.h
        src/Forest/NormalBottom.h
        src/Forest/NormalTop.h
        src/Forest/TransLonely.h
        src/Forest/TransNormalTop.h
        src/Forest/Forest.h
        src/Forest/NodeHandle.h
        src/Forest/DataNodeHandle.h
        src/FindingRichestRegion.h
        src/Forest/TransLonelyHolder.h
        src/Forest/TransNormalTopHolder.h
)
