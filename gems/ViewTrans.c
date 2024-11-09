/*
3D Viewing and Rotation Using Orthonormal Bases
by Steve Cunningham
from "Grahics Gems", Academic Press, 1990
*/

/*
 * Transformations are presented as 4 by 3 matrices, omitting the
 * fourth column to save memory.
 *
 * Functions are used from the Graphics Gems vector C library
 */


#include "GraphicsGems.h"		

typedef float Transform[4][3];

void BuildViewTransform(Point3 VRP, Point3 EP, Point3 UP, Transform T )
{
	Vector3	U, V, N;
	float	dot;

	/*
	 * Compute vector  N = EP - VRP  and normalize  N
	 */
	N.x = EP.x - VRP.x; N.y = EP.y - VRP.y; N.z = EP.z - VRP.z;
	V3Normalize(&N);

	/*
	 * Compute vector  V = UP - VRP
	 * Make vector  V  orthogonal to  N  and normalize  V
	 */
	V.x = UP.x - VRP.x; V.y = UP.y - VRP.y; V.z = UP.z - VRP.z;
	dot = (float)V3Dot(&V,&N);
	V.x -= dot * N.x; V.y -= dot * N.y; V.z -= dot * N.z;
	V3Normalize(&V);


	/*
	 * Compute vector  U = V x N  (cross product)
	 */
	V3Cross(&V,&N,&U);

	/*
	 * Write the vectors U, V, and N as the first three rows of the
	 *       first, second, and third columns of  T, respectively
	 */
	T[0][0] = (float)U.x;		/* column 1 , vector U */
	T[1][0] = (float)U.y;
	T[2][0] = (float)U.z;
	T[0][1] = (float)V.x;		/* column 2 , vector V */
	T[1][1] = (float)V.y;
	T[2][1] = (float)V.z;
	T[0][2] = (float)N.x;		/* column 3 , vector N */
	T[1][2] = (float)N.y;
	T[2][2] = (float)N.z;

	/*
	 * Compute the fourth row of  T  to include the translation of
	 *       VRP  to the origin
	 */
	T[3][0] = (float)(- U.x * VRP.x - U.y * VRP.y - U.z * VRP.z);
	T[3][1] = (float)(- V.x * VRP.x - V.y * VRP.y - V.z * VRP.z);
	T[3][2] = (float)(- N.x * VRP.x - N.y * VRP.y - N.z * VRP.z);

	return;
}


