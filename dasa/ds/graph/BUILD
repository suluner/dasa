licenses(["notice"])  # Apache 2.0

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "union_find",
    srcs = [
        "union_find.cc",
    ],
    hdrs = [
        "union_find.h",
    ],
)

cc_library(
    name = "adj_table_graph",
    srcs = [
        "adj_table_graph.cc",
    ],
    hdrs = [
        "adj_table_graph.h",
    ],
    deps = [
        ":union_find",
    ],
)

cc_library(
    name = "adj_matrix_graph",
    srcs = [
        "adj_matrix_graph.cc",
    ],
    hdrs = [
        "adj_matrix_graph.h",
    ],
)
