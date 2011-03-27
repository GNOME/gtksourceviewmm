#!/usr/bin/env perl

# Copyright 2011 Krzesimir Nowak
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or 
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
# GNU General Public License for more details. 
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

# This script truncates the Source/source/SOURCE_ prefixes from c++ file
# includes/class names/enum values respectively.
# usage: ./source_truncate.pl file1 file2 file3 dir1/*.{h,cc} ...

use strict;
use warnings;

use IO::File;
use Fcntl qw(:seek);

my @files = (
  'buffer',
  'completion',
  'completionactivation',
  'completioncontext',
  'completioninfo',
  'completionitem',
  'completionproposal',
  'completionprovider',
  'completionwords',
  'gutter',
  'gutterrenderer',
  'gutterrendererpixbuf',
  'gutterrenderertext',
  'language',
  'languagemanager',
  'mark',
  'markattributes',
  'markup',
  'printcompositor',
  'style',
  'stylescheme',
  'styleschememanager',
  'undomanager',
  'view'
);
my @types = (
  'BracketMatchType',
  'Buffer',
  'Completion',
  'CompletionActivation',
  'CompletionContext',
  'CompletionInfo',
  'CompletionItem',
  'CompletionProposal',
  'CompletionProvider',
  'CompletionWords',
  'DrawSpacesFlags',
  'Gutter',
  'GutterRenderer',
  'GutterRendererAlignmentMode',
  'GutterRendererPixbuf',
  'GutterRendererState',
  'GutterRendererText',
  'Language',
  'LanguageManager',
  'Mark',
  'MarkAttributes',
  'Markup',
  'PrintCompositor',
  'SmartHomeEndType',
  'Style',
  'StyleScheme',
  'StyleSchemeManager',
  'UndoManager',
  'View'
);
my @enum_values = (
  'COMPLETION_ACTIVATION',
  'BRACKET_MATCH',
  'DRAW_SPACES',
  'GUTTER_RENDERER_ALIGNMENT_MODE',
  'GUTTER_RENDERER_STATE',
  'SMART_HOME_END'
);
my $files_s = join('|', @files);
my $types_s = join('|', @types);
my $enum_values_s = join ('|', @enum_values);

@files = ();
@types = ();
@enum_values = ();
STDOUT->autoflush();

for my $filename (@ARGV)
{
  print STDOUT join ('', $filename, '... ');
  my $file = IO::File->new ($filename, 'r+');

  unless (defined ($file))
  {
    print STDOUT join ('', 'Failed to open.', "\n");
  }
  else
  {
    my @contents_a = <$file>;
    my $contents = join('', @contents_a);
    @contents_a = ();

    # C++ filenames (also private headers)
    $contents =~ s/(\b)source(($files_s)(_p)?.(h|cc)\b)/$1$2/g;
    # C++ class names
    $contents =~ s/(\b)Source(($types_s)\b)/$1$2/g;
    # C++ enum values
    $contents =~ s/(\b)SOURCE_(($enum_values_s)_)/$1$2/g;
    if ($file->seek (0, SEEK_SET) and $file->truncate (0))
    {
      print $file $contents;
      print STDOUT join ('', 'Done', "\n");
    }
    else
    {
      print STDOUT join ('', 'Failed to either seek or truncate the file.', "\n");
    }
    $file->close();
  }
}
