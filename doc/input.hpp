#pragma once

/*!
 * \file input.hpp
 * \brief Game engine
 * \author Tsunuky
 * \version 0.1
 */

/*! \namespace dg
 * 
 *  namesape dg
 */
namespace dg {

/*! 
 *  \class input
 *  \brief Class for get the status or position of key, button mouse and joysitck
 * 
 */
class input;
/*!
 * Return the boolean status of given key
 *
 * see file keycode.hpp for all key code
 * \param keycode int that represant key
 *
 * **Exemple:**
 * \code{.cpp}
 * if (dg::input::isKeyPress(DG_KEY_...)) // replace the ... by the key you wish
 *      std::cout << DG_KEY_... << " is pressed ! "<< std::endl;
 * \endcode
 *
 */
inline static bool input::isKeyPress(int keycode);

/*!
 * Return the boolean status of given key in repetition
 *
 * see file keycode.hpp for all key code
 * \param keycode int that represant key
 *
 * **Exemple:**
 * \code{.cpp}
 * if (dg::input::whileKeyPress(DG_KEY_...)) // replace the ... by the key you wish
 *      std::cout << DG_KEY_... << " is pressed ! "<< std::endl;
 * \endcode
 *
 */
inline static bool input::whileKeyPress(int keycode);


/*!
 * Return the boolean status of given Button
 *
 * see file keycode.hpp for all Button code
 * \param button int that represant key
 *
 * **Exemple:**
 * \code{.cpp}
 * if (dg::input::isButtonPress(DG_MOUSE_BUTTON_...)) // replace the ... by the button you wish
 *      std::cout << DG_MOUSE_BUTTON_... << " is pressed ! "<< std::endl;
 * \endcode
 *
 */
inline static bool input::isButtonPress(int button);


/*!
 * Return the boolean status of given Button in repetition
 *
 * see file keycode.hpp for all Button code
 * \param button int that represant key
 *
 * **Exemple:**
 * \code{.cpp}
 * if (dg::input::whileButtonPress(DG_MOUSE_BUTTON_...)) // replace the ... by the button you wish
 *      std::cout << DG_MOUSE_BUTTON_... << " is pressed ! "<< std::endl;
 * \endcode
 *
 */
inline static bool input::whileButtonPress(int button);

/*!
 * Return a pair of int representing the mousse position
 *
 * **Exemple:**
 * \code{.cpp}
 * std::pair<int, int> tmp = dg::input::getMousePos();
 * 
 * std::cout << "X: " << tmp.first << " Y: " << tmp.second << std::endl;
 * \endcode
 *
 */
inline static std::pair<int, int> input::getMousePos();

/*!
 * Return a int representing the mousse position int the axe X
 *
 * **Exemple:**
 * \code{.cpp}
 * int tmp = dg::input::getMouseX();
 * 
 * std::cout << "X: " << tmp << std::endl;
 * \endcode
 *
 */
inline static int input::getMouseX() {return _instance->getMouseXImpl();};

/*!
 * Return a int representing the mousse position int the axe Y
 *
 * **Exemple:**
 * \code{.cpp}
 * int tmp = dg::input::getMouseY();
 * 
 * std::cout << "Y: " << tmp << std::endl;
 * \endcode
 *
 */
inline static int input::getMouseY() {return _instance->getMouseXImpl();};

/*! \namespace keyMap
 * 
 *  namesape keymap
 */
namespace keyMap {
}

/*! \namespace buttonMap
 * 
 *  namesape buttonMap
 */
namespace buttonMap {

}

/*! \namespace mouseDataPos
 * 
 *  namesape mouseDataPos
 */
namespace mouseDataPos {

}

}