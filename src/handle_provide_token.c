#include "plugin.h"

// EDIT THIS: Adapt this function to your needs! Remember, the information for tokens are held in
// `msg->token1` and `msg->token2`. If those pointers are `NULL`, this means the ethereum app didn't
// find any info regarding the requested tokens!
void handle_provide_token(ethPluginProvideInfo_t *msg) {
    // This plugin does not require token information for the approveTx method.
    // The fields for decimals, ticker, and token_found have been removed from context_s.
    // Thus, this function is now a no-op.

    // context_t *context = (context_t *) msg->pluginContext; // context is not used.

    // msg->additionalScreens can be set here if needed, but not for approveTx.
    msg->result = ETH_PLUGIN_RESULT_OK;
}
