#ifndef _CONTEXT_MENU_H_
#define _CONTEXT_MENU_H_

#include "database.h"
#include "proclist.h"

/// Show a right-click menu for a given wxListCtrl.
/// We assume that the selected items are the actionable ones,
/// and that the list stores Database::Address-es in its
/// ItemData.
void FunctionMenu(wxListCtrl *list, Database *database);

#endif
