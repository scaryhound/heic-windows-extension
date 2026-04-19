#include<libheif/heif.h>
#include<iostream>

void test_engine() {
    // 1. Power on the engine
    heif_init(nullptr);
    heif_context* ctx = heif_context_alloc();

    // 2. Try to open the test image
    heif_error err = heif_context_read_from_file(ctx, "test.heic", nullptr);
    
    if (err.code != heif_error_Ok) {
        std::cerr << "Engine Failed! Could not read test.heic: " << err.message << std::endl;
    } else {
        // 3. Extract the main image
        heif_image_handle* handle;
        heif_context_get_primary_image_handle(ctx, &handle);
        
        int width = heif_image_handle_get_width(handle);
        int height = heif_image_handle_get_height(handle);
        
        std::cout << "SUCCESS! Engine decoded the image." << std::endl;
        std::cout << "Image Dimensions: " << width << " x " << height << " pixels." << std::endl;
        
        heif_image_handle_release(handle);
    }

    // 4. Power down
    heif_context_free(ctx);
    heif_deinit();
}

int main() {
    test_engine();
    return 0;
}