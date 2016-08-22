#ifndef MENUOPTION_H
#define MENUOPTION_H

#define DEBUG 0 // Activate / deactivate debug mode.


enum MenuOption {
    // Initialized with decimal asci codes for current character (49 == '1').
    ENTER_BARCOD = 49, // 1. Enter 10-digit code.
    CHANGE_ITEM_PRICE, // 2. Change the price of an item.
    CUSTOMER_INFO, // 3. Display customer information about the purchase.
    ADD_ITEM, // 4. Add item to the store.
    CLEAR_INVOICE = 67, // C. Clear invoice.
    DISPLAY_TOTAL = 84, // T. Print Total.
    AMOUNT_MONEY = 71, // G. Amount of money.
    HELP, // Help (automatic 72)
    EXIT = 48 // Exit
};

#endif /* MENUOPTION_H */

