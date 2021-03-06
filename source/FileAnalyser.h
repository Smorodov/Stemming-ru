﻿/**
* \file
* \brief Header file with class for file analysis
*
* This file contains the definition of the class for analyze the input file
*/
#ifndef FILE_ANALYSER_H
#define FILE_ANALYSER_H
#pragma once

#include "stdafx.h"

/**
* \brief Class for file analysis
*/
class FileAnalyser
{
public:

	/**
	* \brief Convert the input text into the map of stemms
	*
	* \param[in] filestream Input stream - text
	*
	* \return map of stemms
	*/
	static textmap stemm(std::ifstream &filestream);

	/**
	* \brief Print the result of program in the output file
	*
	* \param[in] inputFileName Input file name
	* \param[in] outputFileName Output file name
	* \param[in] textmap Map with words and their stemms
	*/
	static void save(const std::string &inputFileName, const std::string &outputFileName, const textmap textmap);

	/**
	* \brief Class destructor
	*/
	~FileAnalyser();
};

#endif //FILE_ANALYSER_H