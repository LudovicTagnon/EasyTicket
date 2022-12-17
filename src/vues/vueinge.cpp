#include "vueinge.h"

VueInge::VueInge(Ingenieur ingenieur, EasyTicket& easyTicket)
 : VueIngeTech(easyTicket)
 , ingenieur(ingenieur)
 , page(1)
{

}

void VueInge::on_PrendreButton_clicked() {
    int index = getIndexOfSelected();
    if(index == -1) return;
    
    easyTicket.pushWindow(new VuePriseTicket(easyTicket, ingenieur, easyTicket.getTicketManager().getTickets().at(index)));
}