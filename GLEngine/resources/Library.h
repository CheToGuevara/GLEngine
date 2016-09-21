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


#include "config.h"
#include "scene/Node.h"


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
			static const Library* get();


			/**
			* Description
			* Method to add Resource
			*/
			void addResource(Node * node);

			/**
			* Description
			* Method to get Resource
			*/
			Node* getChildren(std::string name);



			///@}

			/** @name Attributes */
			///@{



			///@}

		protected:

			/**
			* Description
			*
			*/
			Library(void);
			/**
			* Description
			*
			*/
			~Library(void);



		private:

			std::map< std::string, Node* > library;

		};
	

#endif  //__STRIP__RESOURCES__LIBRARY__