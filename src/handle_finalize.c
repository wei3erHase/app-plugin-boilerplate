#include "plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    msg->uiType = ETH_UI_TYPE_GENERIC;
    msg->numScreens = 2;  // For APPROVE_TX: actionContract and nonce
    msg->result = ETH_PLUGIN_RESULT_OK;

    // No token lookups (tokenLookup1, tokenLookup2) are needed for APPROVE_TX.
    // No beneficiary check is needed for APPROVE_TX.
}
