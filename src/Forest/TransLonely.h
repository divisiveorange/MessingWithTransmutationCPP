#pragma once
#include "Lonely.h"
#include "Middle.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransLonely : protected Lonely<T>, PaddingForTrans<Lonely<T>, NormalTop<T>, Middle<T>> {

    };
}