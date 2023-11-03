// #ifndef ZOMBE
// #define ZOMBE

// #include <string>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>

// namespace heros {

//     class Zombi {
//         private:
//             sf::Texture _textur;
//             sf::Srite _zombi_srite;
//         public:
//             Zombi(const std::string& image)
//             {
//                 if ( texture.loadFromFile("image.png", sf::IntRect(0, 0, 32, 32)) ) {
//                     _zombi_textur.setFromFile(_image);
//                     _zombi_sprite.setTexture(_zombi_textur);
//                     _zombie_sprite.setTextureRect(sf::Rect(0, 0, 30, 30));
//                     _zombi_sprite.setPosition(10, 870);
//                     return;
//                 }
//                 std::cout << "Some error whit image.png" << std::endl;
//             }

//             sf::Sprite move_left()
//             {
//                 return _zombi_sprite;
//             }

//             sf::Sprite move_right()
//             {
//                 return _zombi_sprite;
//             }

//             sf::Sprite move_douwn()
//             {
//                 return _zombi_sprite;
//             }

//             sf::Sprite move_up()
//             {
//                 return _zombi_sprite;
//             }
//     };
// } // namespace heros
// #endif // ZOMBE