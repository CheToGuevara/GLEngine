/**
* @file    Library.h
* @brief
* @author  Aaron Sujar <aaronsujar@gmail.com>
* @date
* @remarks Copyright (c) GMRV/URJC. All rights reserved.
*          Do not distribute without further notice.
*/
#ifndef __LIBRARY__
#define __LIBRARY__


#include "../config.h"
#include "../scene/Node.h"
#include "../scene/Light.h"
#include "../scene/Camera.h"


class  Library
		{

		public:

			/** @name Constructors and destructors  */
			///@{



			///@}

			/** @name Methods */
			///@{

			/**
			* Description
			* Method to add Resource
			*/
			static Library* get();
			static Library* get(int argc, char** argv);


			/**
			* Description
			* Method to add Resource
			*/
			void addResource(std::string name, Node * node);

			/**
			* Description
			* Method to add Resource
			*/
			void addCamera(Camera * camera);

			/**
			* Description
			* Method to add Resource
			*/
			void addLight(Light * light);

			/**
			* Description
			* Method to get Resource
			*/
			Node* getChildren(std::string name);

			/**
			* Description
			* Method to get Resource
			*/
			void InitOGL();


			/**
			* Description
			* Method to get Resource
			*/
			void Update();

			/**
			* Description
			* Method to get Resource
			*/
			void MainLoop();


			static void renderFunc();
			static void resizeFunc(int width, int height);
			static void idleFunc();
			static void keyboardFunc(unsigned char key, int x, int y);
			static void mouseFunc(int button, int state, int x, int y);

			///@}

			/** @name Attributes */
			///@{
			


			///@}

		protected:

			/**
			* Description
			*
			*/
			Library(int argc, char** argv);
			/**
			* Description
			*
			*/
			~Library(void);



		private:

			std::map< std::string, Node* > _nodes;
			std::map< std::string, Light* > lights;
			Camera * _camera;

		};
	

#endif  //__STRIP__RESOURCES__LIBRARY__