#include "vueinge.h"

VueInge::VueInge(Ingenieur ingenieur, EasyTicket& easyTicket)
 : VueIngeTech(easyTicket)
 , ingenieur(ingenieur)
 , page(1)
{

}