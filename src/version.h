#define MUDA_VERSION_MAJOR 1
#define MUDA_VERSION_MINOR 7
#define MUDA_VERSION_PATCH 0

#define MUDA_BACKWARDS_COMPATIBLE_VERSION_MAJOR 1
#define MUDA_BACKWARDS_COMPATIBLE_VERSION_MINOR 0
#define MUDA_BACKWARDS_COMPATIBLE_VERSION_PATCH 0

#define MudaMakeVersion(major, minor, patch) ((patch) | ((minor) << 16) | ((major) << 24))

#define MUDA_CURRENT_VERSION MudaMakeVersion(MUDA_VERSION_MAJOR, MUDA_VERSION_MINOR, MUDA_VERSION_PATCH)
#define MUDA_BACKWARDS_COMPATIBLE_VERSION MudaMakeVersion(MUDA_BACKWARDS_COMPATIBLE_VERSION_MAJOR, \
                                                            MUDA_BACKWARDS_COMPATIBLE_VERSION_MINOR, \
                                                            MUDA_BACKWARDS_COMPATIBLE_VERSION_PATCH)
