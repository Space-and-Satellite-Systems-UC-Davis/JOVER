# How to Write the Docs
## The Basics
There is a lot of different software used here so it's good to start with defining what they do:
- [Doxygen](https://www.doxygen.nl/index.html) is a documentation generator which will take the special doxygen-formatted comments in our code and transform it into xml files which are consumed by Breathe. It does not work directly with Read The Docs so we need another documentation generator.
- [Sphinx](https://www.sphinx-doc.org/en/master/) is a documentation generator which is integrated with Read The Docs well. It does not read C and doxygen-format comments, so we rely on Breathe to bridge the gap.
- [MyST](https://myst-parser.readthedocs.io/en/latest/) is a Sphinx extension allowing us to use Markdown instead of reStructuredText. Sphinx and Breathe use "directives" for automatic work like putting the doxygen comments into the page. They are presented in the rST format. To use them in markdown, see <https://myst-parser.readthedocs.io/en/latest/syntax/roles-and-directives.html>. 
- [Breathe](https://breathe.readthedocs.io/en/latest/index.html) acts as a bridge which allows us to insert doxygen information into the documentation through Sphinx.
- [Read The Docs](https://about.readthedocs.com/)(RTD) is the website which offers free hosting to open source projects like us.
There are two document formats which we may use. Stick to [Markdown](https://www.markdownguide.org/getting-started/) (.md). We are technically allowed to use [reStructuredText](https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html) (.rst) as that is what Sphinx uses by default, but it's uncommon elsewhere in comparison to Markdown. Only use rST if you have a good reason.

When you submit a PR and every time you add a commit, RTD will automatically start compiling the documentation. Opening up the list of checks performed, you should be able to find the RTD task and open a preview of what the documentation would look like if your PR is merged. Verify everything looks like it should.

## Adding a new page
Mostly everything is contained inside of the `docs` directory. Placing a Markdown file somewhere in `docs/source` would make it searchable but it won't appear in the bar on the left nor can it be found by following links in the wiki. Include them in the table of contents and provide a link using the [toctree](https://www.sphinx-doc.org/en/master/usage/restructuredtext/directives.html#table-of-contents) directive. There are a couple of these in pages like the main pages for Firmware and Controls software teams.

Instead of waiting for RTD to compile it everytime, you can compile it locally to see how your changes look. To do that:
1. Change directory to `docs/source`.
2. Make sure you have doxygen installed as a command line program.
3. Have Python installed and add dependecies with `python -m pip install -r ../requirements.txt`.
4. Run the build script `sh build_docs.sh`.
5. Open `docs/source/html/index.html` in your browser. It should look pretty much like the RTD website.

## Documenting with Doxygen 
Wikipedia has a pretty good page giving examples of doxygen-formatted comments: <https://en.wikipedia.org/wiki/Doxygen>. Make sure you start with `/**` and not single star `/*`.

Include such comments above every function in your header files. At least include `@brief`, `@param` for any parameters and `@return` for any return value. You may also like to includes notes or warnings to clarify to use of a certain function.

To add a page describing the header, create a new file `<Filename>.md` somewhere that it belongs under `docs/source`. Include it in the toctree of another document like `Firmware.md` or `Controls.md`. Include a short description of the component or feature at the top, then include the following below:

````
```{doxygenfile} <Filename>.md
   :project: JOVER
```
````

Once built, it should list all of the documented functions in `<Filename>.md`