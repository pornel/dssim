/**
 * Use cargo build --release to create target/releaes/libdssim_core.a
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Configuration for the comparison
 */
typedef struct Dssim Dssim;

/**
 * Abstract wrapper for images. See [`Dssim::create_image()`]
 */
typedef struct DssimImage_f32 DssimImage;

/**
 * Create new context for comparisons
 */
struct Dssim *dssim_new(void);

/**
 * Free the context
 */
void dssim_free(struct Dssim *d);

/**
 * Take sRGB RGBA pixels and preprocess them into image format that can be compared.
 *
 * Pixels are copied. Returns NULL on error.
 *
 * Call `dssim_free_image` to free memory when the image is no longer needed.
 */
DssimImage *dssim_create_image_rgba(struct Dssim *dssim,
                                    const uint8_t *pixels,
                                    uint32_t width,
                                    uint32_t height);

/**
 * Free image data
 */
void dssim_free_image(DssimImage *img);

/**
 * Compare these two images.
 *
 * `img1` can be reused for multiple comparisons.
 *
 * Don't forget to free images and DSSIM context when done.
 */
double dssim_compare(struct Dssim *dssim, const DssimImage *img1, const DssimImage *img2);