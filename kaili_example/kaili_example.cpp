#include <iostream>
#include <kaili.h>

int main(int argc, char* argv[])
{
	glm::vec3 x(1.0f);
	glm::vec3 y(2.0f);

	glm::vec3 z = add(x, y);

	std::cout << "x + y = (" << z.x << ", " << z.y << ", " << z.y << ")" << std::endl;

	print_vk_extension_and_layer();

	return EXIT_SUCCESS;
}