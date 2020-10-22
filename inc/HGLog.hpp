#pragma once

#define HGLOG(fmt, ...) do { HGLog (__FILE__, __PRETTY_FUNCTION__, __LINE__, fmt, __VA_ARGS__); } while (0)
#define HGASSERT(p, msg) do { if (!(p)) { HGLOG("assert(%s) failed: %s\n", #p, msg); HGExit(-1); } } while (0)
#define HGASSERT1(p) HGASSERT(p, "No description")

void HGLog (const char *filename, const char *func, int line, const char *fmt, ...);
void HGExit (int status);