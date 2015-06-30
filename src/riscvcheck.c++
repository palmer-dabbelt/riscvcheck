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

#include <libriscvcheck/model.h++>
#include <libriscvcheck/model_list.h++>
#include <libriscvcheck/util/option.h++>
#include <iostream>
#include <cstring>

int main(int argc, const char **argv)
{
    libriscvcheck::model::ptr gold = nullptr;
    libriscvcheck::model::ptr dut  = nullptr;

    for (auto i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--gold") == 0) {
            gold = libriscvcheck::model_list::lookup(argv[i+1]);
            i++;
        } else if (strcmp(argv[i], "--dut") == 0) {
            dut = libriscvcheck::model_list::lookup(argv[i+1]);
            i++;
        } else {
            std::cerr << "Unknown argument " << argv[i];
            abort();
        }

    }

    if ((gold == nullptr) || (dut == nullptr)) {
        std::cerr << "riscvcheck --gold <gold> --dut <dut>\n"
                  << "  Runs random tests on two RISC-V implementations\n";
        exit(1);
    }
}
