#pragma once
/*
 * gles_immediate_stubs.h  —  Android / OpenGL ES compatibility shim
 *
 * On ES 2.0, fixed-function / immediate-mode APIs are no-ops.
 * On ES 1.1, they forward to the real library functions via dlsym so that
 * the ES 1.1 fallback path (pre-2012 devices) still works correctly.
 *
 * glColor* is intentionally NOT stubbed here — it is handled by macros
 * in common.h that route through glx_set_color4f().
 */
#ifdef OPENGL_ES
#include <dlfcn.h>

extern int gles_version;

/* ── ES 1.x constants that may not be in GLES2 headers ──────────────────── */
#  ifndef GL_QUADS
#    define GL_QUADS 0x0007
#  endif
#  ifndef GL_ALPHA_TEST
#    define GL_ALPHA_TEST 0x0BC0
#  endif
#  ifndef GL_LIGHTING
#    define GL_LIGHTING 0x0B50
#  endif
#  ifndef GL_LIGHT0
#    define GL_LIGHT0 0x4000
#  endif
#  ifndef GL_LIGHT1
#    define GL_LIGHT1 0x4001
#  endif
#  ifndef GL_FOG
#    define GL_FOG 0x0B60
#  endif
#  ifndef GL_COLOR_MATERIAL
#    define GL_COLOR_MATERIAL 0x0B57
#  endif
#  ifndef GL_NORMALIZE
#    define GL_NORMALIZE 0x0BA1
#  endif
#  ifndef GL_TEXTURE_ENV
#    define GL_TEXTURE_ENV 0x2300
#  endif
#  ifndef GL_TEXTURE_ENV_MODE
#    define GL_TEXTURE_ENV_MODE 0x2200
#  endif
#  ifndef GL_MODULATE
#    define GL_MODULATE 0x2100
#  endif
#  ifndef GL_COMBINE
#    define GL_COMBINE 0x8570
#  endif
#  ifndef GL_PROGRAM_POINT_SIZE
#    define GL_PROGRAM_POINT_SIZE 0x8642
#  endif
#  ifndef GL_POINT_DISTANCE_ATTENUATION
#    define GL_POINT_DISTANCE_ATTENUATION 0x8129
#  endif

/* ── Forwarding stubs ────────────────────────────────────────────────────── *
 * Each stub: on ES 1.1, calls the real GL function via dlsym (cached).
 *            on ES 2.0, is a no-op.                                         */

static inline void glBegin(int m) {
	if(gles_version < 2) {
		static void (*fn)(int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int))dlsym(RTLD_DEFAULT, "glBegin"); done = 1; }
		if(fn) fn(m);
		return;
	}
	(void)m;
}

static inline void glEnd(void) {
	if(gles_version < 2) {
		static void (*fn)(void) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(void))dlsym(RTLD_DEFAULT, "glEnd"); done = 1; }
		if(fn) fn();
		return;
	}
}

static inline void glVertex2f(float x, float y) {
	if(gles_version < 2) {
		static void (*fn)(float, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(float, float))dlsym(RTLD_DEFAULT, "glVertex2f"); done = 1; }
		if(fn) fn(x, y);
		return;
	}
	(void)x; (void)y;
}

static inline void glTexCoord2f(float s, float t) {
	if(gles_version < 2) {
		static void (*fn)(float, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(float, float))dlsym(RTLD_DEFAULT, "glTexCoord2f"); done = 1; }
		if(fn) fn(s, t);
		return;
	}
	(void)s; (void)t;
}

static inline void glAlphaFunc(int func, float ref) {
	if(gles_version < 2) {
		static void (*fn)(int, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, float))dlsym(RTLD_DEFAULT, "glAlphaFunc"); done = 1; }
		if(fn) fn(func, ref);
		return;
	}
	(void)func; (void)ref;
}

static inline void glShadeModel(int mode) {
	if(gles_version < 2) {
		static void (*fn)(int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int))dlsym(RTLD_DEFAULT, "glShadeModel"); done = 1; }
		if(fn) fn(mode);
		return;
	}
	(void)mode;
}

static inline void glLightfv(int light, int pname, const float* params) {
	if(gles_version < 2) {
		static void (*fn)(int, int, const float*) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int, const float*))dlsym(RTLD_DEFAULT, "glLightfv"); done = 1; }
		if(fn) fn(light, pname, params);
		return;
	}
	(void)light; (void)pname; (void)params;
}

static inline void glLightf(int light, int pname, float param) {
	if(gles_version < 2) {
		static void (*fn)(int, int, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int, float))dlsym(RTLD_DEFAULT, "glLightf"); done = 1; }
		if(fn) fn(light, pname, param);
		return;
	}
	(void)light; (void)pname; (void)param;
}

static inline void glLightModelfv(int pname, const float* params) {
	if(gles_version < 2) {
		static void (*fn)(int, const float*) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, const float*))dlsym(RTLD_DEFAULT, "glLightModelfv"); done = 1; }
		if(fn) fn(pname, params);
		return;
	}
	(void)pname; (void)params;
}

static inline void glNormal3f(float x, float y, float z) {
	if(gles_version < 2) {
		static void (*fn)(float, float, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(float, float, float))dlsym(RTLD_DEFAULT, "glNormal3f"); done = 1; }
		if(fn) fn(x, y, z);
		return;
	}
	(void)x; (void)y; (void)z;
}

static inline void glFogi(int pname, int param) {
	if(gles_version < 2) {
		static void (*fn)(int, int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int))dlsym(RTLD_DEFAULT, "glFogi"); done = 1; }
		if(fn) fn(pname, param);
		return;
	}
	(void)pname; (void)param;
}

static inline void glFogf(int pname, float param) {
	if(gles_version < 2) {
		static void (*fn)(int, float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, float))dlsym(RTLD_DEFAULT, "glFogf"); done = 1; }
		if(fn) fn(pname, param);
		return;
	}
	(void)pname; (void)param;
}

static inline void glFogfv(int pname, const float* params) {
	if(gles_version < 2) {
		static void (*fn)(int, const float*) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, const float*))dlsym(RTLD_DEFAULT, "glFogfv"); done = 1; }
		if(fn) fn(pname, params);
		return;
	}
	(void)pname; (void)params;
}

static inline void glFogx(int pname, int param) {
	if(gles_version < 2) {
		static void (*fn)(int, int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int))dlsym(RTLD_DEFAULT, "glFogx"); done = 1; }
		if(fn) fn(pname, param);
		return;
	}
	(void)pname; (void)param;
}

static inline void glPushMatrix(void) {
	if(gles_version < 2) {
		static void (*fn)(void) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(void))dlsym(RTLD_DEFAULT, "glPushMatrix"); done = 1; }
		if(fn) fn();
		return;
	}
}

static inline void glPopMatrix(void) {
	if(gles_version < 2) {
		static void (*fn)(void) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(void))dlsym(RTLD_DEFAULT, "glPopMatrix"); done = 1; }
		if(fn) fn();
		return;
	}
}

static inline void glMatrixMode(int mode) {
	if(gles_version < 2) {
		static void (*fn)(int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int))dlsym(RTLD_DEFAULT, "glMatrixMode"); done = 1; }
		if(fn) fn(mode);
		return;
	}
	(void)mode;
}

static inline void glLoadIdentity(void) {
	if(gles_version < 2) {
		static void (*fn)(void) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(void))dlsym(RTLD_DEFAULT, "glLoadIdentity"); done = 1; }
		if(fn) fn();
		return;
	}
}

static inline void glTexEnvi(int target, int pname, int param) {
	if(gles_version < 2) {
		static void (*fn)(int, int, int) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int, int))dlsym(RTLD_DEFAULT, "glTexEnvi"); done = 1; }
		if(fn) fn(target, pname, param);
		return;
	}
	(void)target; (void)pname; (void)param;
}

static inline void glTexEnvfv(int target, int pname, const float* params) {
	if(gles_version < 2) {
		static void (*fn)(int, int, const float*) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, int, const float*))dlsym(RTLD_DEFAULT, "glTexEnvfv"); done = 1; }
		if(fn) fn(target, pname, params);
		return;
	}
	(void)target; (void)pname; (void)params;
}

static inline void glPointSize(float size) {
	if(gles_version < 2) {
		static void (*fn)(float) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(float))dlsym(RTLD_DEFAULT, "glPointSize"); done = 1; }
		if(fn) fn(size);
		return;
	}
	(void)size;
}

static inline void glPointParameterfv(int pname, const float* params) {
	if(gles_version < 2) {
		static void (*fn)(int, const float*) = NULL;
		static int done = 0;
		if(!done) { fn = (void (*)(int, const float*))dlsym(RTLD_DEFAULT, "glPointParameterfv"); done = 1; }
		if(fn) fn(pname, params);
		return;
	}
	(void)pname; (void)params;
}

#endif /* OPENGL_ES */
