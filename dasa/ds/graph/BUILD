licenses(["notice"])  # Apache 2.0

package(default_visibility = ["//visibility:public"])

cc_library(
    name="union_find",
    srcs=[
        "union_find.cc",
    ],
    hdrs=[
        "union_find.h",
    ],
)

cc_library(
    name="graph",
    srcs=[
        "graph.cc",
    ],
    hdrs=[
        "graph.h",
    ],
    deps = [
        ":union_find",
    ],
)
