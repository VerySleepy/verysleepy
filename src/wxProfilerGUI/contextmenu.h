#ifndef _CONTEXT_MENU_H_
#define _CONTEXT_MENU_H_

#include "database.h"
#include "proclist.h"

#include <set>

void FunctionMenu(wxWindow *window, const Database::Symbol *sym, Database *database, wxPropertyGrid *filters, std::set<Database::Symbol::ID>& highlights);

#endif
