/**
 * @file src/fileinfo/file_information/file_information_types/export_table.cpp
 * @brief Export table.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "fileinfo/file_information/file_information_types/export_table.h"
#include "fileinfo/file_information/file_information_types/type_conversions.h"

namespace fileinfo {

/**
 * Constructor
 */
ExportTable::ExportTable() : table(nullptr)
{

}

/**
 * Destructor
 */
ExportTable::~ExportTable()
{

}

/**
 * Get number of exports in table
 * @return Number of exports in table
 */
std::size_t ExportTable::getNumberOfExports() const
{
	return table ? table->getNumberOfExports() : 0;
}

/**
 * Get export name
 * @param position Index of selected export from table (indexed from 0)
 * @return Export name
 */
std::string ExportTable::getExportName(std::size_t position) const
{
	const auto *record = table ? table->getExport(position) : nullptr;
	return record ? record->getName() : "";
}

/**
 * Get export address
 * @param position Index of selected export from table (indexed from 0)
 * @param format Format of resulting string (e.g. std::dec, std::hex)
 * @return Export address
 */
std::string ExportTable::getExportAddressStr(std::size_t position, std::ios_base &(* format)(std::ios_base &)) const
{
	const auto *record = table ? table->getExport(position) : nullptr;
	return record ? getNumberAsString(record->getAddress(), format) : "";
}

/**
 * Get export ordinal number
 * @param position Index of selected export from table (indexed from 0)
 * @param format Format of resulting string (e.g. std::dec, std::hex)
 * @return Export ordinal number
 */
std::string ExportTable::getExportOrdinalNumberStr(std::size_t position, std::ios_base &(* format)(std::ios_base &)) const
{
	unsigned long long ordinal;
	const auto *record = table ? table->getExport(position) : nullptr;
	return record && record->getOrdinalNumber(ordinal) ? getNumberAsString(ordinal, format) : "";
}

/**
 * Set export table data
 * @param exportTable Instance of class with original information about export table
 */
void ExportTable::setTable(const fileformat::ExportTable *exportTable)
{
	table = exportTable;
}

/**
 * Find out if there are any exports
 * @return @c true if there are some exports, @c false otherwise
 */
bool ExportTable::hasRecords() const
{
	return table ? table->hasExports() : false;
}

} // namespace fileinfo
