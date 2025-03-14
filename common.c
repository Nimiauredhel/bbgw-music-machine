#include "common.h"

/**
 * Global flag set by OS termination signals
 * and polled by functions to allow graceful termination.
 */
bool should_terminate = false;

/**
 * Hooks up OS signals to our custom handler.
 */
void initialize_signal_handler(void)
{
    should_terminate = false;

    struct sigaction action = {0};
    action.sa_handler = signal_handler;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGHUP, &action, NULL);
}

/**
 * Handles selected OS signals.
 * Termination signals are caught to set the should_terminate flag
 * which signals running functions that they should attempt graceful termination.
 */
void signal_handler(int signum)
{
    switch (signum)
    {
        case SIGINT:
        case SIGTERM:
        case SIGHUP:
            should_terminate = true;
            break;
    }
}
