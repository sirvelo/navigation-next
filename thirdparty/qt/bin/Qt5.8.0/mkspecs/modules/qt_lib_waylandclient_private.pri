QT.waylandclient_private.VERSION = 5.8.0
QT.waylandclient_private.MAJOR_VERSION = 5
QT.waylandclient_private.MINOR_VERSION = 8
QT.waylandclient_private.PATCH_VERSION = 0
QT.waylandclient_private.name = QtWaylandClient
QT.waylandclient_private.module =
QT.waylandclient_private.libs = $$QT_MODULE_LIB_BASE
QT.waylandclient_private.includes = $$QT_MODULE_INCLUDE_BASE/QtWaylandClient/5.8.0 $$QT_MODULE_INCLUDE_BASE/QtWaylandClient/5.8.0/QtWaylandClient
QT.waylandclient_private.frameworks =
QT.waylandclient_private.depends = core_private gui_private waylandclient service_support_private
QT.waylandclient_private.uses =
QT.waylandclient_private.module_config = v2 internal_module
QT.waylandclient_private.enabled_features = wayland-client drm-egl-server wayland-egl
QT.waylandclient_private.disabled_features = libhybris-egl-server wayland-brcm xcomposite-egl xcomposite-glx
QMAKE_LIBS_WAYLAND-CLIENT = -lwayland-client
QMAKE_LIBS_WAYLAND-CURSOR = -lwayland-cursor
QMAKE_LIBS_WAYLAND-EGL = -lwayland-egl -lwayland-client
