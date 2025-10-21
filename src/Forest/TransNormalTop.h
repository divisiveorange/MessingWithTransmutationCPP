#pragma once
#include "Middle.h"
#include "NormalTop.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransNormalTop : protected NormalTop<T>, PaddingForTrans<NormalTop<T>, NormalTop<T>, Middle<T>> {

    };
}
