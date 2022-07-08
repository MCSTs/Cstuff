#include "total.h"

const char *f_type(char *name)
{
	char *dot;

	dot = strrchr(name, '.');
	if (dot == NULL)
		return "text/plain; charset=utf-8";
	if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
		return "text/html; charset=utf-8";
	if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
		return "application/x-jpg";
	if (strcmp(dot, ".gif") == 0)
		return "image/gif";
	if (strcmp(dot, ".png") == 0)
		return "image/png";
	if (strcmp(dot, ".css") == 0)
		return "text/css";
	if (strcmp(dot, ".au") == 0)
		return "autio/basic";
	if (strcmp(dot, ".wav") == 0)
		return "autio/wav";
	if (strcmp(dot, ".avi") == 0)
		return "video/x-msvideo";
	if (strcmp(dot, ".mov") == 0)
		return "video/quicktime";
	if (strcmp(dot, ".mpeg") == 0)
		return "video/mpeg";
	if (strcmp(dot, ".vrml") == 0)
		return "model/vrml";
	if (strcmp(dot, ".midi") == 0)
		return "audio/midi";
	if (strcmp(dot, ".mp3") == 0)
		return "audio/mpeg";
	if (strcmp(dot, ".ogg") == 0)
		return "application/ogg";
	if (strcmp(dot, ".pac") == 0)
		return "application/x-ns-proxy-autoconfig";
	if (strcmp(dot, ".ico") == 0)
		return "application/x-icb";

	return "text/plain; charset=utf-8";
	
}
