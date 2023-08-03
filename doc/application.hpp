#pragma once

#include <memory>

/*!
 * \file application.hpp
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
 *  \struct appliSpecification
 *  \brief Aplication basic data
 *  \param name string contain application name
 *  \param workingDirectory string contain the pwd of the current working space
 */
struct appliSpecification;
/*! 
 *  \class application
 *  \brief Main class of the application
 *
 */
class application;

/*!
 *  Constructor of class
 *
 *  \param  name give the name of the application if no name give it's use default value 'Window'
 *  \brief The constructor initialize the log, keymap and buttonmap class
 *  and create a windows with default value for size for now
 *  create the inmguilayer and push it on overlay postition
 * \hiderefby
 * \hiderefs
*/
application::application();

/*!default destrcutor*/
application::~application();

/*!
 *  Create a instance of application
 *
 * **Exemple:**
 * \code{.cpp}
 * dg::application *Variable_name = createApplication();
 *  \endcode
 *
 */
application application::createApplication();

/*!
 *  Browse through all the events and dispatch them on the different layer 
 *
 *  **References:**
 */
void application::onEvent();

/*!
 * Launch the application loop
 *
 *  **References:**
 */
void application::run();

/*!
 * Close the application
 *
 *  **References:**
 */
bool application::onEventClose(dg::windowCloseEvent &e);

/*!
 * Push a layer on the layer stack
 *
 *  **References:**
 */
void application::pushLayer(dg::layer *layer);

/*!
 * Push a overlay on the layer stack
 *
 *  **References:**
 */
void application::pushOverlay(dg::layer *overlay);

/*!
 * A getter that returns a reference to an instance of application
 *
 *  **References:**
 */
inline static application &application::get();

/*!
 * A getter that returns a reference to a main window of application class
 *
 *  **References:**
 */
inline dg::window_API &application::getWindow();

/*!Unique pointeur on main window*/
std::unique_ptr<dg::window_API> application::_win;
/*!Unique pointeur on vertex buffer class*/
std::unique_ptr<vertexBuffer> application::_vertexBuffer;
/*!Unique pointeur on index buffer class*/
std::unique_ptr<indexBuffer> application::_indexBuffer;
/*!Raw pointer on stack of imgui specifique layer*/
imGuiLayer *application::_imguiLayer;
/*!Stack of all layer of application*/
dg::layerStack application::_layerStack;
/*!Boolean say if progran run or stop*/
bool application::isRunning = true;
/*!Id of the last shader compile*/
u_int application::shader;


/*! Static raw pointeur contain the application */
static application *application::_instance;

}