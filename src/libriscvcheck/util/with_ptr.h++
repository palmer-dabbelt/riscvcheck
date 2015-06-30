/*
 * Copyright (C) 2015 Palmer Dabbelt
 *   <palmer.dabbelt@eecs.berkeley.edu>
 *
 * This file is part of riscvcheck.
 * 
 * riscvcheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * riscvcheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with riscvcheck.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBRISCVCHECK__UTIL__WITH_PTR_HXX
#define LIBRISCVCHECK__UTIL__WITH_PTR_HXX

#include <memory>
#include <iostream>

namespace libriscvcheck {
    namespace util {
        /* Gives a short name for a shared pointer to a particular
         * type.  Things are meant to be a subclass of this so they
         * get access to this type. */
        template<typename T> class with_ptr {
        public:
            typedef std::shared_ptr<T> ptr;
            typedef std::shared_ptr<const T> const_ptr;
            typedef std::weak_ptr<T> weak_ptr;
        };
    }
}

#endif
