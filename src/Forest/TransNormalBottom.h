#pragma once
#include "Middle.h"
#include "NormalTop.h"
#include "NormalBottom.h"
#include "../GeneralLib/PaddingForTrans.h"
namespace Forest {
    template <class T>
    class TransNormalBottom: protected NormalBottom<T>, PaddingForTrans<NormalBottom<T>, NormalTop<T>, Middle<T>> {

    };
}
