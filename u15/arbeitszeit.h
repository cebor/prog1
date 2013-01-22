#ifndef _AZINC_
#define _AZINC_

#pragma pack(push, 1) // Alignment 1 Byte
typedef struct
{
	short int id;
	char date[9];
	float h;
} t_arbeitszeit;

typedef struct
{
	short int id;
	char name[20];
} t_mitarbeiter;

#pragma pack(pop)
#endif
