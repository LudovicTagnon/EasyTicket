#include "vuetech.h"

VueTech::VueTech(Technicien technicien, EasyTicket& easyTicket)
 : VueIngeTech(easyTicket)
 , technicien(technicien)
{

}

void VueTech::on_PrendreButton_clicked() {
    int index = getIndexOfSelected();
    if(index == -1) return;

    easyTicket.pushWindow(new VuePriseTicket(easyTicket, technicien, easyTicket.getTicketManager().getTickets().at(index)));
}