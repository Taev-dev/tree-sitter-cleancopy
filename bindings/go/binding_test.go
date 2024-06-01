package tree_sitter_cleancopy_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-cleancopy"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_cleancopy.Language())
	if language == nil {
		t.Errorf("Error loading Cleancopy grammar")
	}
}
