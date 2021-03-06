/*
 * Copyright (c) 2017-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __ARM_COMPUTE_TEST_ARRAYACCESSOR_H__
#define __ARM_COMPUTE_TEST_ARRAYACCESSOR_H__

#include "arm_compute/runtime/Array.h"
#include "tests/IArrayAccessor.h"

namespace arm_compute
{
namespace test
{
/** ArrayAccessor implementation for @ref Array objects. */
template <typename T>
class ArrayAccessor : public IArrayAccessor<T>
{
public:
    /** Create an accessor for the given @p array.
     *
     * @param[in, out] array To be accessed array.
     */
    ArrayAccessor(Array<T> &array)
        : _array{ array }
    {
    }

    /** Prevent instances of this class from being copy constructed */
    ArrayAccessor(const ArrayAccessor &) = delete;
    /** Prevent instances of this class from being copied */
    ArrayAccessor &operator=(const ArrayAccessor &) = delete;
    /** Allow instances of this class to be move constructed */
    ArrayAccessor(ArrayAccessor &&) = default;
    /** Allow instances of this class to be moved */
    ArrayAccessor &operator=(ArrayAccessor &&) = default;

    size_t num_values() const override
    {
        return _array.num_values();
    }

    T *buffer() override
    {
        return _array.buffer();
    }

    void resize(size_t num) override
    {
        _array.resize(num);
    }

    T &at(size_t index) const override
    {
        ARM_COMPUTE_ERROR_ON(_array.buffer() == nullptr);
        ARM_COMPUTE_ERROR_ON(index >= num_values());
        return _array.buffer()[index];
    }

private:
    Array<T> &_array;
};
} // namespace test
} // namespace arm_compute
#endif /* __ARM_COMPUTE_TEST_ARRAYACCESSOR_H__ */
