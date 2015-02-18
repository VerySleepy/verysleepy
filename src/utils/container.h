/*=====================================================================
container.h
--------------
Copyright (C) Vladimir Panteleev

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

http://www.gnu.org/copyleft/gpl.html..
=====================================================================*/

#pragma once

#include <unordered_map>

/// Find an entry with the specified key and return its value,
/// or, failing that, return a default value.
template<typename MAP>
static typename MAP::value_type::second_type map_get(const MAP &map, const typename MAP::key_type &key, const typename MAP::value_type::second_type defaultValue = MAP::value_type::second_type())
{
	MAP::const_iterator i = map.find(key);
	if (i == map.end())
		return defaultValue;
	return i->second;
}

/// Add or find an entry to the map with the specified key.
/// Copies true to *pinserted if a new entry was added, false if an existing one was found.
/// Returns a reference to the new/existing value.
template<class MAP>
static typename MAP::value_type::second_type& map_emplace(MAP &map, const typename MAP::key_type &key, bool *pinserted=NULL)
{
	auto pair = map.emplace(std::make_pair(key, MAP::value_type::second_type()));
	if (pinserted) *pinserted = pair.second;
	return pair.first->second;
}

/// Add or find an entry in a string[id] vector / id[string] map pair, and return its ID.
template<typename ID>
static ID map_string(std::vector<std::wstring> &list, std::unordered_map<std::wstring, ID>&map, std::wstring key)
{
	bool inserted;
	ID &id = map_emplace(map, key, &inserted);
	if (inserted) // new entry
	{
		list.push_back(key);
		return id = list.size() - 1;
	}
	else // existing entry
		return id;
}

#include <unordered_set>

/// Nicer wrapper around set::count.
template<class SET>
static bool set_get(const SET &set, const typename SET::key_type &key)
{
	return set.count(key) != 0;
}

/// Make sure the specified item is / isn't in the set, according to a boolean.
template<class SET>
static void set_set(SET &set, const typename SET::key_type &key, bool value)
{
	if (value)
		set.insert(key);
	else
	{
		SET::const_iterator i = set.find(key);
		if (i != set.end())
			set.erase(i);
	}
}
