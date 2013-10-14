/*
* Simd Library.
*
* Copyright (c) 2011-2013 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "Simd/SimdLoad.h"
#include "Simd/SimdStore.h"
#include "Simd/SimdConst.h"
#include "Simd/SimdMemory.h"
#include "Simd/SimdBgrToGray.h"
#include "Simd/SimdBase.h"

namespace Simd
{
    namespace Base
    {
        void BgraToGray(const uchar * bgra, size_t width, size_t height, size_t bgraStride, uchar * gray, size_t grayStride)
        {
            for(size_t row = 0; row < height; ++row)
            {
				const uchar * pBgra = bgra + row*bgraStride;
				uchar * pGray = gray + row*grayStride;
				for(const uchar *pGrayEnd = pGray + width; pGray < pGrayEnd; pGray += 1, pBgra += 4)
				{
					*pGray = BgrToGray(pBgra[0], pBgra[1], pBgra[2]);
				}
            }
        }
    }
}