#include "plugin.h"

// EDIT THIS: You need to adapt / remove the static functions (set_send_ui, set_receive_ui ...) to
// match what you wish to display.

static bool set_action_contract_ui(ethQueryContractUI_t *msg, context_t *context) {
    strlcpy(msg->title, "Action Contract", msg->titleLength);
    msg->msg[0] = '0';
    msg->msg[1] = 'x';
    // We need a random chainID for legacy reasons with `getEthAddressStringFromBinary`.
    // Setting it to `0` will make it work with every chainID :)
    uint64_t chainid = 0;
    return getEthAddressStringFromBinary(context->action_contract, msg->msg + 2, chainid);
}

static bool set_nonce_ui(ethQueryContractUI_t *msg, context_t *context) {
    strlcpy(msg->title, "Nonce", msg->titleLength);
    return amountToString(context->nonce,
                          sizeof(context->nonce),
                          0,
                          "",
                          msg->msg,
                          msg->msgLength);
}

void handle_query_contract_ui(ethQueryContractUI_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    bool ret = false;

    // msg->title is the upper line displayed on the device.
    // msg->msg is the lower line displayed on the device.

    // Clean the display fields.
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);

    // EDIT THIS: Adapt the cases for the screens you'd like to display.
    // Since APPROVE_TX is the only selector, we don't need to switch on context->selectorIndex anymore.
    switch (msg->screenIndex) {
        case 0:
            ret = set_action_contract_ui(msg, context);
            break;
        case 1:
            ret = set_nonce_ui(msg, context);
            break;
        default:
            PRINTF("Received an invalid screenIndex\n");
            // ret will be false, leading to ETH_PLUGIN_RESULT_ERROR
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}
