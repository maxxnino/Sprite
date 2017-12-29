#pragma once
#include <vector>

struct SKillSet
{
	enum SkillName
	{
		FFF, FFW, FFL, FFE, FWW, FLL, FEE, FWL, FWE, FLE,
		WWW, WWL, WWE, WLL, WEE, WLE,
		LLL,LLE,LEE,
		EEE,
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
		{ SKillSet::SkillName::FFF,  "FFF"},
		{ SKillSet::SkillName::FFW,  "FFW" },
		{ SKillSet::SkillName::FFL,  "FFL" },
		{ SKillSet::SkillName::FFE,  "FFE" },
		{ SKillSet::SkillName::FWW,  "FWW" },
		{ SKillSet::SkillName::FLL,  "FLL" },
		{ SKillSet::SkillName::FEE,  "FEE" },
		{ SKillSet::SkillName::FWL,  "FWL" },
		{ SKillSet::SkillName::FWE,  "FWE" },
		{ SKillSet::SkillName::FLE,  "FLE" },

		{ SKillSet::SkillName::WWW,  "WWW" },
		{ SKillSet::SkillName::WWL,  "WWL" },
		{ SKillSet::SkillName::WWE,  "WWE" },
		{ SKillSet::SkillName::WLL,  "WLL" },
		{ SKillSet::SkillName::WEE,  "WEE" },
		{ SKillSet::SkillName::WLE,  "WLE" },

		{ SKillSet::SkillName::LLL,  "LLL" },
		{ SKillSet::SkillName::LLE,  "LLE" },
		{ SKillSet::SkillName::LEE,  "LEE" },

		{ SKillSet::SkillName::EEE,  "EEE" },
	};
};