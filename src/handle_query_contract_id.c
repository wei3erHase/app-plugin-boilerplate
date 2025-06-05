#include "plugin.h"

// Sets the first screen to display.
void handle_query_contract_id(ethQueryContractID_t *msg) {
    // msg->name will be the upper sentence displayed on the screen.
    // msg->version will be the lower sentence displayed on the screen.

    // For the first screen, display the plugin name and version.
    // Since this plugin now only handles approveTx, we can set these unconditionally.
    strlcpy(msg->name, "Approve TX", msg->nameLength);
    strlcpy(msg->version, "1.0.0", msg->versionLength);
    msg->result = ETH_PLUGIN_RESULT_OK;
}
