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

#ifndef LIBRISCVCHECK__UTIL__OPTION_HXX
#define LIBRISCVCHECK__UTIL__OPTION_HXX

namespace libriscvcheck {
    namespace util {
        /* FIXME: there must be a std::option of some sort? */
        template <typename T> class option {
        private:
            bool _valid;
            T _value;

        public:
            option(void)
                : _valid(false),
                  _value()
                {
                }

            option(const T& value)
                : _valid(true),
                  _value(value)
                {
                }

        public:
            bool valid(void) const { return _valid; }
            const T& value(void) const {
                if (valid() == true)
                    return _value;
                std::cerr << "option::value() without valid()\n";
                abort();
            }

        public:
            void operator=(const T& value) {
                _valid = true;
                _value = value;
            }
        };
    }
}

#endif
