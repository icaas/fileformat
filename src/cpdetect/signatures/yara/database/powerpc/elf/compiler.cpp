/**
 * @file src/cpdetect/signatures/yara/database/powerpc/elf/compiler.cpp
 * @brief Database of signatures.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

const char *powerpcElfCompiler =
R"powerpc_elf_comp(rule rule_1_GCC__gcc_powerpc_elf
{
	meta:
		tool = "C"
		name = "GCC"
		version = "4.5.1 - 4.5.2"
		pattern = "780B297C3600215400000038F0FF2194A603087C000001900?10003D????A885????0048E0FF2194A602087C1?00?193??10?03F24000190????1?881?00?1930000802F1?00?1931?00?193??009E40??10?03F??10?03F??????3B??????3B"
	strings:
		$1 = { 78 0B 29 7C 36 00 21 54 00 00 00 38 F0 FF 21 94 A6 03 08 7C 00 00 01 90 0? 10 00 3D ?? ?? A8 85 ?? ?? 00 48 E0 FF 21 94 A6 02 08 7C 1? 00 ?1 93 ?? 10 ?0 3F 24 00 01 90 ?? ?? 1? 88 1? 00 ?1 93 00 00 80 2F 1? 00 ?1 93 1? 00 ?1 93 ?? 00 9E 40 ?? 10 ?0 3F ?? 10 ?0 3F ?? ?? ?? 3B ?? ?? ?? 3B }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_ppc64le_1
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "100000480000000000000000000000000020207C18008240000061E8080081381?00E03F?0??BF390070AD39040000480?00E03F?????F3?A603?97?2004804E??0061E8EA000038020000447802007C2000804E00000000??00??????00??????00?1E8"
	strings:
		$1 = { 10 00 00 48 00 00 00 00 00 00 00 00 00 00 00 00 00 20 20 7C 18 00 82 40 00 00 61 E8 08 00 81 38 1? 00 E0 3F ?0 ?? BF 39 00 70 AD 39 04 00 00 48 0? 00 E0 3F ?? ?? ?F 3? A6 03 ?9 7? 20 04 80 4E ?? 00 61 E8 EA 00 00 38 02 00 00 44 78 02 00 7C 20 00 80 4E 00 00 00 00 ?? 00 ?? ?? ?? 00 ?? ?? ?? 00 ?1 E8 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_ppc64_1
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "00000000000?????00000000000000000000000000000000E86100003881000848000008000000003FE0000?3??F????7??903A64E800420E86100??380000EA440000027C0002784E80002000000000E86100??E88100??E8A100??3800000544000002"
	strings:
		$1 = { 00 00 00 00 00 0? ?? ?? 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 E8 61 00 00 38 81 00 08 48 00 00 08 00 00 00 00 3F E0 00 0? 3? ?F ?? ?? 7? ?9 03 A6 4E 80 04 20 E8 61 00 ?? 38 00 00 EA 44 00 00 02 7C 00 02 78 4E 80 00 20 00 00 00 00 E8 61 00 ?? E8 81 00 ?? E8 A1 00 ?? 38 00 00 05 44 00 00 02 }
	condition:
		for any of them : ( $ at elf.entry_point )
}
rule gc_ppc64_2
{
	meta:
		tool = "C"
		name = "gc"
		language = "Go"
		pattern = "000000000005F??0000000000000000000000000000000000000000000000000E86100003881000848000008000000003FE00006399F???07D8903A64E800420E8610022380000EA440000027C0002784E800020000000000000000000000000E8610020"
	strings:
		$1 = { 00 00 00 00 00 05 F? ?0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 E8 61 00 00 38 81 00 08 48 00 00 08 00 00 00 00 3F E0 00 06 39 9F ?? ?0 7D 89 03 A6 4E 80 04 20 E8 61 00 22 38 00 00 EA 44 00 00 02 7C 00 02 78 4E 80 00 20 00 00 00 00 00 00 00 00 00 00 00 00 E8 61 00 20 }
	condition:
		for any of them : ( $ at elf.entry_point )
})powerpc_elf_comp";
