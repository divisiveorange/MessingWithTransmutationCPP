#pragma once
#include "Middle.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransMiddle : protected Middle<T>, PaddingForTrans<Middle<T>, NormalTop<T>, Middle<T>> {

    };
}
