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

#include "model_list.h++"
using namespace libriscvcheck;

std::map<std::string, std::function<model::ptr(void)>> model_list::_models;

model::ptr model_list::lookup(const std::string& name)
{
    auto l = _models.find(name);
    if (l == _models.end())
        return NULL;

    return l->second();
}

void model_list::insert(const std::string& name,
                        std::function<model::ptr(void)> cons)
{
    _models[name] = cons;
}
