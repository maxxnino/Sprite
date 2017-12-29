#pragma once
#include <vector>

struct SKillSet
{
	enum SkillName
	{
		skillFFF,
		skillFFW,
		skillFFE,
		skillFWW,
		skillFEE,
		skillFWE,
		skillWWW,
		skillWWE,
		skillWEE,
		skillEEE,
		None
	};
	SkillName skillName;
	std::string nameSet;
};


class SkillLookup
{
public:
	std::vector<SKillSet> skillSetContainer =
	{ 
		{ SKillSet::SkillName::skillFFF,  "FFF"},
		{ SKillSet::SkillName::skillFFW,  "FFW" },
		{ SKillSet::SkillName::skillFFE,  "FFE" },
		{ SKillSet::SkillName::skillFWW,  "FWW" },
		{ SKillSet::SkillName::skillFEE,  "FEE" },
		{ SKillSet::SkillName::skillFWE,  "FWE" },
		{ SKillSet::SkillName::skillWWW,  "WWW" },
		{ SKillSet::SkillName::skillWWE,  "WWE" },
		{ SKillSet::SkillName::skillWEE,  "WEE" },
		{ SKillSet::SkillName::skillEEE,  "EEE" }
	};
};