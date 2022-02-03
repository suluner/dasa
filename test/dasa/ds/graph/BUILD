licenses(["notice"])  # Apache 2.0

package(default_visibility = ["//visibility:public"])

cc_test(
    name = "test_adj_table_graph",
    srcs = [
        "test_adj_table_graph.cc",
    ],
    deps = [
        "//dasa/ds/graph:adj_table_graph",
        "@com_google_googletest//:gtest",
    ],
)

cc_test(
    name = "test_adj_matrix_graph",
    srcs = [
        "test_adj_matrix_graph.cc",
    ],
    deps = [
        "//dasa/ds/graph:adj_matrix_graph",
        "@com_google_googletest//:gtest",
    ],
)
