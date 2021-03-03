
## Design Decisions

All classes inherit the base Package class which holds all
set and get functionalities.

All Packages call the Package constructor and additionally set their own costs  
using a virtual func which is overriden for every different package type.

Certian Packages inherit special package types as for example the  
OvernightDelivery has to inherit TwoDayDelivery as we need the cost of that  
package type aswell and we have to call its specific override of calculateCost.  
In case this happens the base class is indirectly inherited through that class.

PrintCosts takes the address of any instance of package class and because of the virtual  
overrides always gets the according packet types costs.
